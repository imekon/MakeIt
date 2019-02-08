function draw_text()
	root = Scene()
	Scene.set_root(root)

	c = Colour.from_rgba(255, 0, 0, 255)
	f = Font()
	f:load("fonts/modes___.ttf")
	t = Text()
	t.position = Vector2(100, 70)
	t:set_font(f)
	t:set_string("This is some text")
	t:set_fill_colour(c)
	t:set_character_size(16)

	root:add_child(t)
end