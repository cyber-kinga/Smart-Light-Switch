const char Index[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      html {
        font-family: Lato;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
        text-shadow: 2px 2px 5px #fff;
      }
      .btn{
        color: white;
        background-color: #1cb4fa;
        padding: 20px 55px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        border: 5px solid #fff;
        cursor: pointer;
        font-weight: bold;
      }
    </style>
  </head>
  <body>
    <br>
    <h1 style="color: #1cb4fa;">Control your Single Light Smart Switcher 1.0</h1>
    <br><br>
    <button type="button" onclick="sendSignal('on')" class="btn btn-on">On</button>
    <br><br>
    <button type="button" onclick="sendSignal('off')" class="btn btn-off">Off</button>
    
    <script>
      function sendSignal(state) { 
          var httpRequest = new XMLHttpRequest();
          httpRequest.open("GET", "setLight?state=" + state, true);   
          httpRequest.send();
      }
    </script>
  </body>
</html>
)=====";
