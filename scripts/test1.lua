function create_vec()
	crate = Texture()
	crate:load("textures/crate.png")

	s = Sprite()
	s:set_texture(crate)
	s.position = Vector2(100,200)

	root = Scene()
	Scene.set_root(root)

	root:add_child(s)
end