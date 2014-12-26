function Page1_Self_OnKeyPress(e) {
    if (e.keyCode === 4) {
        Application.exit();
    }
}
function Page1_Self_OnShow() {
    //Comment following block for removing navigationbar/actionbar sample
    //Copy this code block to every page onShow
    header.init(this);
    header.setTitle("Page1");
    header.setRightItem("RItem");
    header.setLeftItem();
    /**/
}
function Page1_TextButton1_OnPressed(e) {
    Data.GetWeather_InDSet.CityName = Pages.Page1.EditBox1.text;
    Data.GetWeather_InDSet.commit();
    SMF.Net.GetWeather.run(true);
}
function Page1_TextButton2_OnPressed(e) {
    Device.Media.pickFromGallery({
        type : [SMF.MediaType.image],
        onSuccess : function (e) {
            Pages.Page1.Image1.image = e.file;
            alert(e.filename);
        },
        onCancel : function (e) {
            alert("cancelled");
        },
        onError : function (e) {
            alert("failed");
        }
    });
}
function Page1_ImageButton1_OnPressed(e) {
    Pages.Page3.show();
}
function Page1_TextButton3_OnPressed(e){
    Pages.Page2.show();
}