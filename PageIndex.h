const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="author" content="Kinga Madej">
    <style>
      html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
        text-shadow: 2px 2px 5px #fff;
      }
      .btn{
        background-color: #1cb4fa;
        color: white;
        padding: 20px 55px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        z-index: 10;
        border: 5px solid #fff;
        cursor: pointer;
        font-weight: bold;
      }
    </style>
  </head>

    <br>
    <h1 style="z-index: 100; color: #1cb4fa;">Control your Smart Light Switcher</h1>
    <br><br>
    
    <button type="button" onclick="sendData('on')" class="btn btn-on">On</button>
    <br><br>
    <button type="button" onclick="sendData('off')" class="btn btn-off">Off</button>
    <br><br>
    
    <label><span id="isiStatusSER1"></span></label>
    
    <script>
      function sendData(state) { 
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) { 
              document.getElementById("SERstate1").innerHTML = this.responseText;     
            }
          };
          xhttp.open("GET", "setLight?state=" + state, true);   
          xhttp.send();
      }
    </script>

  </body>
</html>
)=====";
