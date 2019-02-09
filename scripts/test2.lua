function draw_text()
	root = Scene()
	Scene.set_root(root)

	c = Colour.from_rgba(255, 100, 50, 255)
	f = Font()
	f:load("fonts/modes___.ttf")
	t = Text()
	t.position = Vector2(50, 30)
	t:set_font(f)
	t:set_string("Score: 60")
	t:set_fill_colour(c)
	t:set_character_size(24)

	root:add_child(t)
end