configuration = { width = 1280, height = 800, title = "This is MakeIt sample" }

function game_startup()
	crate = Texture()
	crate:load("textures/crate.png")

	ball = Texture()
	ball:load("textures/ball.png")

	s1 = Sprite()
	s1:set_texture(crate)
	s1.origin = Vector2(16, 16)
	s1.position = Vector2(100, 100)

	s2 = Sprite()
	s2:set_texture(ball)
	s2.position = Vector2(300, 100)
end

function game_run()
end

function game_shutdown()
end
