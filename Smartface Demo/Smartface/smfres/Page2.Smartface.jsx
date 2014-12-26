function Page2_Self_OnShow(e){
    Device.Media.getGalleryItems({
    type:SMF.MediaType.Image, //it can be image or video
onSuccess:function(e){
            var i;
            var ln=e.length
            Data.Dataset1.clear();
            for (i=0;i<ln;i++){
                //Pages.Page2.RepeatBox1.Image2=e[i].file;
                Data.Dataset1.add();
                Data.Dataset1.foto=e[i].filename;
                Data.Dataset1.adi = e[i].filename;
               // Pages.Page1.Image1.image = e[0].file; //where you want to show these photos and sort length
               }
               Data.Dataset1.commit();
               Data.notify("Data.Dataset1");
            }});
}
function Page2_RepeatBox1_OnSelectedItem(e){
    Data.Dataset1.seek(e.rowIndex);
   // alert(Data.Dataset1.foto);
    Pages.Page4.show();
}
function Page2_TextButton1_OnPressed(e){
    Pages.back();
}