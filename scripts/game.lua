configuration = { width = 1280, height = 800, title = "This is MakeIt sample" }

function game_startup()
	t = Texture.create("textures/crate.png")
	s = Sprite.create()
	s:set_texture(t)
	s.position = Vector2.create(100, 100)
end

function game_run()
end

function game_shutdown()
end
