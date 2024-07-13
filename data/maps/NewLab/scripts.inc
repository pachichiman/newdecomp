NewLab_MapScripts::
	.byte 0


NewLab_EventScript_Pokeball::
# 5 "data/maps/NewLab/scripts.pory"
	lockall
# 6 "data/maps/NewLab/scripts.pory"
	showmonpic SPECIES_TOGEPI, 10, 3
# 7 "data/maps/NewLab/scripts.pory"
	msgbox NewLab_EventScript_Pokeball_Text_0, MSGBOX_YESNO
# 8 "data/maps/NewLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewLab_EventScript_Pokeball_2
# 30 "data/maps/NewLab/scripts.pory"
	hidemonpic
# 31 "data/maps/NewLab/scripts.pory"
	msgbox NewLab_NotChosen
NewLab_EventScript_Pokeball_1:
# 33 "data/maps/NewLab/scripts.pory"
	waitmessage
# 34 "data/maps/NewLab/scripts.pory"
	releaseall
	end

NewLab_EventScript_Pokeball_2:
# 9 "data/maps/NewLab/scripts.pory"
	givemon SPECIES_TOGEPI, 12, ITEM_KINGS_ROCK
# 10 "data/maps/NewLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewLab_EventScript_Pokeball_5
# 17 "data/maps/NewLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewLab_EventScript_Pokeball_6
# 25 "data/maps/NewLab/scripts.pory"
	hidemonpic
# 26 "data/maps/NewLab/scripts.pory"
	msgbox NewLab_EventScript_Pokeball_Text_2
	goto NewLab_EventScript_Pokeball_1

NewLab_EventScript_Pokeball_5:
# 11 "data/maps/NewLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 12 "data/maps/NewLab/scripts.pory"
	msgbox NewLab_EventScript_Pokeball_Text_1
# 13 "data/maps/NewLab/scripts.pory"
	removeobject 1
# 14 "data/maps/NewLab/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 15 "data/maps/NewLab/scripts.pory"
	call NicknamePartyMon
	goto NewLab_EventScript_Pokeball_1

NewLab_EventScript_Pokeball_6:
# 18 "data/maps/NewLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 19 "data/maps/NewLab/scripts.pory"
	msgbox NewLab_EventScript_Pokeball_Text_1
# 20 "data/maps/NewLab/scripts.pory"
	removeobject 1
# 21 "data/maps/NewLab/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 22 "data/maps/NewLab/scripts.pory"
	call NicknameBoxMon
	goto NewLab_EventScript_Pokeball_1


NicknamePartyMon::
# 40 "data/maps/NewLab/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 41 "data/maps/NewLab/scripts.pory"
	hidemonpic
# 42 "data/maps/NewLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 43 "data/maps/NewLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 44 "data/maps/NewLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 50 "data/maps/NewLab/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 51 "data/maps/NewLab/scripts.pory"
	hidemonpic
# 52 "data/maps/NewLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 55 "data/maps/NewLab/scripts.pory"
	msgbox NicknameBoxMon_Text_0
	return

NicknameBoxMon_2:
# 53 "data/maps/NewLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


NewLab_EventScript_Pokeball_Text_0:
# 7 "data/maps/NewLab/scripts.pory"
	.string "Do you want to choose Togepi?$"

NewLab_EventScript_Pokeball_Text_1:
# 12 "data/maps/NewLab/scripts.pory"
	.string "Received Togepi$"

NewLab_EventScript_Pokeball_Text_2:
# 26 "data/maps/NewLab/scripts.pory"
	.string "No more room.$"

NicknamePartyMon_Text_0:
# 40 "data/maps/NewLab/scripts.pory"
	.string "Give it a nickname?$"

NicknameBoxMon_Text_0:
# 55 "data/maps/NewLab/scripts.pory"
	.string "Transferred to PC$"

NewLab_NotChosen::
# 58 "data/maps/NewLab/scripts.pory"
	.string "You did not choose the Pokemon$"
