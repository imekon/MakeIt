require "scripts/physics"
-- require "scripts/test1"
-- require "scripts/test2"

configuration = { width = 1280, height = 768, title = "This is MakeIt sample" }

function game_startup()
	setup_physics()
	create_crates()
	create_end_stops()
	-- create_balls()
	-- x = 100
	-- rate = 0.05
end

function game_run(delta)
	-- x = x + rate / delta
	-- if x > 1180 then
	--	x = 100
	-- end
	-- s1.position = Vector2(x, 100)
end

function game_shutdown()
end
