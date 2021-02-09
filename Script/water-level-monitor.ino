#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <NewPing.h>

int trigpin = 2;
int echopin= 0;
long duration,distance;
long fill_height;
long height = 0;
long fill_percentage;

/* Put your SSID & Password */
const char* ssid = "NODEMCU";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

const char index_html[] PROGMEM = {"<!DOCTYPE html>\n<html lang=\"en\" dir=\"ltr\">\n  <head>\n    <meta charset=\"utf-8\" name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <title>WATER MONITOR</title>\n    <link rel=\"stylesheet\" href=\"stylesheet.css\">\n  </head>\n  <body>\n    <h1 class=\"w3-panel w3-border w3-round-xxlarge\"> WATER LEVEL MONITOR </h1>\n    <div class=\"w3-center w3-animate-top\">\n      <center>\n      <h2 class=\" text\"> ENTER THE HEIGHT OF THE TANK (cm)</h2>\n      <form class=\"\" action=\"/action\" method=\"get\">\n        <label for=\"tank_height\"></label>\n        <input class=\"w3-input w3-animate-input\" type=\"text\" style=\"text-align:center;border-style: groove;width:30%\" id =\"tank_height\" name=\"tank_height\" value=\"0\">\n        <br>\n        <input class=\"w3-button w3-red\" type=\"submit\" value=\"Submit\">\n      </form>\n      </center>\n    </div>\n  </body>\n</html>\n"};

const char css[] PROGMEM={"body,html\n{\n  background-image: url();\n  background-repeat: no-repeat;\n  background-size:cover;\n  font-style: normal;\n  font: garamond\n}\nh1\n{\n  font-size: 53px;\n  text-align: center;\n  color: red;\n\n}\n.w3-round-xxlarge{border-radius:32px}\n.w3-border{border:1px solid #ff0000}\n.w3-animate-top{position:relative;animation:animatetop 0.4s}@keyframes animatetop{from{top:-300px;opacity:0} to{top:0;opacity:1}}\n.w3-center{text-align:center!important}\n.w3-animate-input{transition:width 0.4s ease-in-out}\n.w3-input{padding:8px;display:block;border:none;border-bottom:1px solid #ccc;width:100%}\n.w3-button{border:none;display:inline-block;padding:8px 16px;vertical-align:middle;overflow:hidden;text-decoration:none;color:inherit;background-color:inherit;text-align:center;cursor:pointer;white-space:nowrap}\n.w3-red,.w3-hover-red:hover{color:#fff!important;background-color:#f44336!important}\n.text\n{\n  font: garamond;\n  font-size: 30px;\n  padding-top: 170px;\n  padding-left: 25px;\n}\n"};

ESP8266WebServer server(80);
NewPing sonar(trigpin, echopin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.softAP(ssid, password);
  delay(100);
  server.on("/", handle_OnConnect);
  server.on("/stylesheet.css",handle_css);
  server.on("/action", handle_form);
  server.on("/water_level", handle_water_level);
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("HTTP server started");
  Serial.print(WiFi.softAPIP());


}

void loop() {
  // put your main code here, to run repeatedly:

  server.handleClient();
  if (height != 0)
  {
    Serial.println("Height=");
    Serial.print(height);
    duration = sonar.ping_median(5);
    distance = sonar.convert_cm(duration);
    fill_height = height - distance;
    Serial.println("fill_height");
    Serial.print(fill_height);
    fill_percentage = (fill_height*100)/height;
    Serial.println("fill_percentage");
    Serial.print(fill_percentage);

  }


}
void handle_OnConnect()
{
  Serial.println("In root");
  server.send_P(200, "text/html", index_html);
}

void handle_css()
{
server.send_P(200, "text/css",css);
}

void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}


void handle_form()
{
  Serial.println("In form");

  height= atol(server.arg("tank_height").c_str());

  server.send(200,"text/html",send_html());
}

void handle_water_level()
 {
  server.send(200,"text/html",send_html());
}

String send_html()
{
  String ptr ="<!DOCTYPE html>\n<html lang=\"en\" dir=\"ltr\">\n  <head>\n    <meta charset=\"utf-8\" name=\"viewport\" http-equiv=\"refresh\" content=\"5\" content=\"width=device-width, initial-scale=1.0\" >\n    <link rel=\"stylesheet\" href=\"stylesheet.css\">\n    <title>WATER LEVEL MONITOR</title>\n  </head>\n  <body>\n    <h1 class=\"w3-panel w3-border w3-round-xxlarge\">WATER LEVEL MONITOR</h1>\n    <div class=\"w3-center w3-animate-top\">\n      <center>\n      <p class=\" text\"> STATUS(%):<span class=\"w3-button w3-red\">";
  ptr += (int)fill_percentage;
  ptr += "</span></p>\n      </center>\n    </div>\n  </body>\n</html>\n";
  return ptr;
}
