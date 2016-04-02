#ifndef HTML_HEAD_h_
#define HTML_HEAD_h_

#define html_s          ("<!doctype html>\n<html>")

#define html_head_s     ("\n<head>")

#define html_meta       ("\n\t<meta charset=\"utf-8\">\n\t<meta name=\"viewport\" content=\"width=device^width, initial-scale=1.0\">")

#define html_title      ("\n\t<title>Test</title>")

#define js_link         ("\n\t<script src=\"http://ccchart.com/js/ccchart.js\" charset=\"utf-8\"></script>")
// CCCHRAT.js , 

#define html_head_e     ("\n</head>")

#define html_body_s     ("\n<body>")

#define body_canvas     ("\n<canvas id=\"hoge\"></canvas>")

#define js_s            ("\n<script>")

#define js_ccchart      ("var chartdata6 = {\n\t\"config\": {\n\t\t\"title\": \"Bezier Chart2\",\n\t\t\"subTitle\": \"Canvasを使った普通な感じのベジェラインチャートです\",\n\t\t\"type\": \"bezi2\",\n\t\t\"xScaleXOffset\": 4,\n\t\t\"colorSet\": \n\t\t\t\[\"\#666\",\"\#aaa\",\"\#ccc\"\],\n\t\t\"bgGradient\": {\n\t\t\t\"direction\":\"vertical\",\n\t\t\t\"from\":\"\#222\",\n\t\t\t\"to\":\"\#687478\"\n\t\t}\n\t},\n\t\"data\": [\n\t\t\[\"moon\",1,2,3,4,5,6,7,8,9,10,11,12\],\n\t\t\[\"coffee\",52,57,44,50,60,55,68,80,64,41,57,78\],\n\t\t\[\"juice\",30,45,56,40,80,68,76,90,75,52,57,55\],\n\t\t\[\"uron\",20,23,12,20,42,50,72,63,30,20,32,50\]\n\t\]\n};ccchart.init(\'hoge\', chartdata6)\")

#define js_e            ("\n</script>")

#define html_body_e     ("\n</body>")

#define html_e          ("\n</html>")


#endif