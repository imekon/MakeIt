configuration = { width = 1280, height = 800, title = "This is MakeIt sample" }

function game_startup()
	crate = Texture()
	crate:load("textures/crate.png")

	crate_width = crate.width

	ball = Texture()
	ball:load("textures/ball.png")

	root = Scene()
	Scene.set_root(root)

	s1 = Sprite()
	s1:set_texture(crate)
	s1.position = Vector2(100, 100)
	root:add_child(s1)

	s2 = Sprite()
	s2:set_texture(ball)
	-- s2.z = -10
	s2.position = Vector2(125, 100)
	-- root:add_child(s2)

	-- Sprite.sort()
end

function game_run()
end

function game_shutdown()
end
