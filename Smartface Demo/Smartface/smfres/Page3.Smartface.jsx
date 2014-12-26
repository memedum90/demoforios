function Page3_TextButton1_OnPressed(e){
    ad=Pages.Page3.adbox.text.toUpperCase();
    soyad=Pages.Page3.soyadbox.text.toUpperCase();
    dogum=Number(Pages.Page3.dogumbox.text);
    tckimlikno=Number(Pages.Page3.kimlikbox.text);
    tcKimlikValidation.requestString= '<soap:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/">'
 + '<soap:Body>'
   + '<TCKimlikNoDogrula xmlns="http://tckimlik.nvi.gov.tr/WS">'
  +    '<TCKimlikNo>'  +tckimlikno+  '</TCKimlikNo>'
  +    '<Ad>'    +ad+     '</Ad>'
  +    '<Soyad>' +soyad+  '</Soyad>'
 +     '<DogumYili>'  +dogum+    '</DogumYili>'
 +   '</TCKimlikNoDogrula>'
+  '</soap:Body>'
+'</soap:Envelope>';
    tcKimlikValidation.run(true);
}
function Page3_TextButton2_OnPressed(e){
    Pages.Page1.show();
}