<?php
/**
 * @file
 * ding_frontpage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ding_frontpage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ding_frontpage';
  $page->task = 'page';
  $page->admin_title = 'Ding frontpage';
  $page->admin_description = 'Front page.';
  $page->path = 'ding_frontpage';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_ding_frontpage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'ding_frontpage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Ding frontpage',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(),
    ),
  );
  $display = new panels_display();
  $display->layout = 'ding_layout_1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'top_secondary' => NULL,
      'main_content' => NULL,
      'main_left_right' => NULL,
      'main_right_right' => NULL,
      'attachment_4_1' => NULL,
      'attachment_4_2' => NULL,
      'attachment_4_3' => NULL,
      'attachment_4_4' => NULL,
      'attachment_3_1' => NULL,
      'attachment_3_2' => NULL,
      'attachment_3_3' => NULL,
      'attachment_2_1' => NULL,
      'attachment_2_2' => NULL,
      'attachment_1_1' => NULL,
      'primary' => NULL,
      'secondary' => NULL,
      'tertiary' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6795d6ae-3c57-4fb4-b339-3d6373acce88';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-74a49488-f11d-40b6-8211-52e84c8b296a';
    $pane->panel = 'primary';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_tabroll-ding_frontpage_tabroll';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '74a49488-f11d-40b6-8211-52e84c8b296a';
    $display->content['new-74a49488-f11d-40b6-8211-52e84c8b296a'] = $pane;
    $display->panels['primary'][0] = 'new-74a49488-f11d-40b6-8211-52e84c8b296a';
    $pane = new stdClass();
    $pane->pid = 'new-18cfc092-1d0f-42e4-bde8-8a6e314c9bd0';
    $pane->panel = 'primary';
    $pane->type = 'carousel';
    $pane->subtype = 'carousel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '18cfc092-1d0f-42e4-bde8-8a6e314c9bd0';
    $display->content['new-18cfc092-1d0f-42e4-bde8-8a6e314c9bd0'] = $pane;
    $display->panels['primary'][1] = 'new-18cfc092-1d0f-42e4-bde8-8a6e314c9bd0';
    $pane = new stdClass();
    $pane->pid = 'new-b117a6e8-2bdb-48ed-b2ea-5e6600f515a9';
    $pane->panel = 'primary';
    $pane->type = 'ding_campaign_plus';
    $pane->subtype = 'ding_campaign_plus';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'style' => 'ribbon',
      'context' => array(
        0 => 'empty',
        1 => 'empty',
        2 => 'empty',
        3 => 'empty',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b117a6e8-2bdb-48ed-b2ea-5e6600f515a9';
    $display->content['new-b117a6e8-2bdb-48ed-b2ea-5e6600f515a9'] = $pane;
    $display->panels['primary'][2] = 'new-b117a6e8-2bdb-48ed-b2ea-5e6600f515a9';
    $pane = new stdClass();
    $pane->pid = 'new-20a8af4e-90a0-42a4-be60-89cb72e44127';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_news-ding_news_frontpage_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Library news',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '20a8af4e-90a0-42a4-be60-89cb72e44127';
    $display->content['new-20a8af4e-90a0-42a4-be60-89cb72e44127'] = $pane;
    $display->panels['secondary'][0] = 'new-20a8af4e-90a0-42a4-be60-89cb72e44127';
    $pane = new stdClass();
    $pane->pid = 'new-6af18880-acd3-436c-a1e3-39581aa3b62a';
    $pane->panel = 'secondary';
    $pane->type = 'all_opening_hours';
    $pane->subtype = 'all_opening_hours';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'opening_hours_frontpage',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6af18880-acd3-436c-a1e3-39581aa3b62a';
    $display->content['new-6af18880-acd3-436c-a1e3-39581aa3b62a'] = $pane;
    $display->panels['secondary'][1] = 'new-6af18880-acd3-436c-a1e3-39581aa3b62a';
    $pane = new stdClass();
    $pane->pid = 'new-1235d134-3c15-4d11-86e4-a48f9c8737b3';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_event-ding_event_list_frontpage';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1235d134-3c15-4d11-86e4-a48f9c8737b3';
    $display->content['new-1235d134-3c15-4d11-86e4-a48f9c8737b3'] = $pane;
    $display->panels['secondary'][2] = 'new-1235d134-3c15-4d11-86e4-a48f9c8737b3';
    $pane = new stdClass();
    $pane->pid = 'new-21e4a892-88bb-4aa3-9fc4-fa91c0333938';
    $pane->panel = 'tertiary';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_groups-panel_pane_frontpage';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Udvalgte temaer',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '21e4a892-88bb-4aa3-9fc4-fa91c0333938';
    $display->content['new-21e4a892-88bb-4aa3-9fc4-fa91c0333938'] = $pane;
    $display->panels['tertiary'][0] = 'new-21e4a892-88bb-4aa3-9fc4-fa91c0333938';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ding_frontpage'] = $page;

  return $pages;

}
