configuration = { width = 1280, height = 800, title = "This is MakeIt sample" }

function game_startup()
	crate = Texture()
	crate:load("textures/crate.png")

	crate_width = crate.width

	ball = Texture()
	ball:load("textures/ball.png")

	crates = {}
	for i=0,9 do
		s = Sprite()
		s:set_texture(crate)
		s.position = Vector2(100 + i * crate_width, 100)
		crates[i] = s
	end

	s2 = Sprite()
	s2:set_texture(ball)
	-- s2.z = -10
	s2.position = Vector2(125, 100)

	-- Sprite.sort()
end

function game_run()
end

function game_shutdown()
end
