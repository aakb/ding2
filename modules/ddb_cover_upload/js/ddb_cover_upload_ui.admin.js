/**
 * @file
 * Add image editor and handle file upload.
 */

(function ($) {
  Drupal.behaviors.ddbCoverUpload = {
    attach: function (context, settings) {
      var imageHasBeenUploaded = false;
      var currentImageUrl = $('input[name="image_file"]').val();

      var instance = new tui.ImageEditor(document.querySelector('#tui-image-editor'), {
        includeUI: {
          loadImage: {
            path: currentImageUrl,
            name: 'SampleImage'
          },
          locale: ddbCoverUploadUITranslation(),
          theme: ddbCoverUploadUITheme(Drupal.settings.ddbCoverUpload.bashPath),
          initMenu: 'filter',
          menuBarPosition: 'bottom',
          menu: ['crop', 'flip', 'rotate', 'filter'],
        },
        cssMaxWidth: 700,
        cssMaxHeight: 500,
        selectionStyle: {
          cornerSize: 20,
          rotatingPointOffset: 70
        }
      });

      // Handle ajax image upload, when next is clicked.
      $('#edit-next').click(function (event) {
        let self = $(this);

        if (!imageHasBeenUploaded) {
          event.preventDefault();

          const myImage = instance.toDataURL();
          $.ajax({
            type: "POST",
            url: '/admin/config/ting/ddb_cover_upload/ajax',
            dataType: 'text',
            data: {
              is: $('input[name="is"]').val(),
              base64data: myImage
            },
            success: function (result) {
              const json = JSON.parse(result);
              if (json.hasOwnProperty('error') && json.error === null) {
                $('input[name="image_file"]').val(json.uri);
                imageHasBeenUploaded = true;
                self.trigger('click');
              }
              else {
                alert(json.error);
              }
            }
          });
        }
        else {
          imageHasBeenUploaded = false;
        }
      });

      /**
       * Helper function to change and translation strings in the UI.
       */
      function ddbCoverUploadUITranslation() {
        return  {
          'Load': Drupal.t('Upload new image', null, { context: 'ddbCoverUploadUI' }),
        };
      }

      /**
       * Helper function to set lighter theme.
       */
      function ddbCoverUploadUITheme(path) {
        path = '/' + path;
        return {
          'common.bi.image': 'https://uicdn.toast.com/toastui/img/tui-image-editor-bi.png',
          'common.bisize.width': '251px',
          'common.bisize.height': '21px',
          'common.backgroundImage': './img/bg.png',
          'common.backgroundColor': '#fff',
          'common.border': '1px solid #c1c1c1',

          // Header.
          'header.backgroundImage': 'none',
          'header.backgroundColor': 'transparent',
          'header.border': '0px',

          // Load button.
          'loadButton.backgroundColor': '#fff',
          'loadButton.border': '1px solid #ddd',
          'loadButton.color': '#222',
          'loadButton.fontFamily': '\'Noto Sans\', sans-serif',
          'loadButton.fontSize': '12px',

          // Download button.
          'downloadButton.backgroundColor': '#fdba3b',
          'downloadButton.border': '1px solid #fdba3b',
          'downloadButton.color': '#fff',
          'downloadButton.fontFamily': '\'Noto Sans\', sans-serif',
          'downloadButton.fontSize': '12px',

          // Main icons.
          'menu.normalIcon.path': path + '/images/svg/icon-d.svg',
          'menu.normalIcon.name': 'icon-d',
          'menu.activeIcon.path': path + '/images/svg/icon-b.svg',
          'menu.activeIcon.name': 'icon-b',
          'menu.disabledIcon.path': path + '/images/svg/icon-a.svg',
          'menu.disabledIcon.name': 'icon-a',
          'menu.hoverIcon.path': path + '/images/svg/icon-c.svg',
          'menu.hoverIcon.name': 'icon-c',
          'menu.iconSize.width': '24px',
          'menu.iconSize.height': '24px',

          // Submenu primary color.
          'submenu.backgroundColor': 'transparent',
          'submenu.partition.color': '#e5e5e5',

          // Submenu icons.
          'submenu.normalIcon.path': path + '/images/svg/icon-d.svg',
          'submenu.normalIcon.name': 'icon-d',
          'submenu.activeIcon.path': path + '/images/svg/icon-b.svg',
          'submenu.activeIcon.name': 'icon-b',
          'submenu.iconSize.width': '32px',
          'submenu.iconSize.height': '32px',

          // Submenu labels.
          'submenu.normalLabel.color': '#858585',
          'submenu.normalLabel.fontWeight': 'normal',
          'submenu.activeLabel.color': '#000',
          'submenu.activeLabel.fontWeight': 'normal',

          // Checkbox style
          'checkbox.border': '1px solid #ccc',
          'checkbox.backgroundColor': '#fff',

          // Rango style.
          'range.pointer.color': '#333',
          'range.bar.color': '#ccc',
          'range.subbar.color': '#606060',

          'range.disabledPointer.color': '#d3d3d3',
          'range.disabledBar.color': 'rgba(85,85,85,0.06)',
          'range.disabledSubbar.color': 'rgba(51,51,51,0.2)',

          'range.value.color': '#000',
          'range.value.fontWeight': 'normal',
          'range.value.fontSize': '11px',
          'range.value.border': '0',
          'range.value.backgroundColor': '#f5f5f5',
          'range.title.color': '#000',
          'range.title.fontWeight': 'lighter',

          // Color picker style.
          'colorpicker.button.border': '0px',
          'colorpicker.title.color': '#000'
        };
      }
    }
  };
}(jQuery));