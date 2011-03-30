<?php

function theme_lat_media_toolbar_preprocess(&$vars) {
  $items = $vars['latmediatoolbar_items'];
  $vars['latmediatoolbar_items'] = implode(' ', $items);
}