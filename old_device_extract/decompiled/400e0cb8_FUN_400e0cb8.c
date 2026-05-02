// Function : FUN_400e0cb8
// Address  : 0x400e0cb8
// Size     : 551 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e0cb8(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_44 [16];
  undefined4 auStack_34 [2];
  code *pcStack_2c;
  undefined *puStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0be8(auStack_44,"dev_sec_credit");
  puStack_28 = &DAT_400e35a8;
  pcStack_2c = FUN_40183ffc;
  auStack_34[0] = param_1;
  FUN_400e0bf4(param_1,auStack_44,auStack_34);
  (*(code *)&LAB_40183a17_1)(auStack_34);
  FUN_400f0a50(auStack_44);
  FUN_400f0be8(auStack_44,"ev_act_estop");
  puStack_28 = &LAB_400e06a0;
  pcStack_2c = (code *)0x40184014;
  auStack_34[0] = param_1;
  FUN_400e0bf4(param_1,auStack_44,auStack_34);
  (*(code *)&LAB_40183a17_1)(auStack_34);
  FUN_400f0a50(auStack_44);
  FUN_400f0be8(auStack_44," update");
  puStack_28 = (undefined *)0x400e3090;
  pcStack_2c = (code *)&LAB_4018402c;
  auStack_34[0] = param_1;
  FUN_400e0bf4(param_1,auStack_44,auStack_34);
  (*(code *)&LAB_40183a17_1)(auStack_34);
  FUN_400f0a50(auStack_44);
  FUN_400f0be8(auStack_44,"offline status");
  puStack_28 = &LAB_400e3a2c;
  pcStack_2c = (code *)&LAB_40184044;
  auStack_34[0] = param_1;
  FUN_400e0bf4(param_1,auStack_44,auStack_34);
  (*(code *)&LAB_40183a17_1)(auStack_34);
  FUN_400f0a50(auStack_44);
  FUN_400f0be8(auStack_44,"");
  puStack_28 = &LAB_400e2f10;
  pcStack_2c = (code *)&LAB_4018405c;
  auStack_34[0] = param_1;
  FUN_400e0bf4(param_1,auStack_44,auStack_34);
  (*(code *)&LAB_40183a17_1)(auStack_34);
  FUN_400f0a50(auStack_44);
  FUN_400f0be8(auStack_44,"_config");
  puStack_28 = &DAT_400e46bc;
  pcStack_2c = (code *)&LAB_40184074;
  auStack_34[0] = param_1;
  FUN_400e0bf4(param_1,auStack_44,auStack_34);
  (*(code *)&LAB_40183a17_1)(auStack_34);
  FUN_400f0a50(auStack_44);
  FUN_400f0be8(auStack_44,"_config");
  puStack_28 = (undefined *)0x400e114c;
  pcStack_2c = (code *)&LAB_4018408c;
  auStack_34[0] = param_1;
  FUN_400e0bf4(param_1,auStack_44,auStack_34);
  (*(code *)&LAB_40183a17_1)(auStack_34);
  FUN_400f0a50(auStack_44);
  FUN_400f0be8(auStack_44,"a_check");
  puStack_28 = &DAT_400e138c;
  pcStack_2c = (code *)&LAB_401840a4;
  auStack_34[0] = param_1;
  FUN_400e0bf4(param_1,auStack_44,auStack_34);
  (*(code *)&LAB_40183a17_1)(auStack_34);
  FUN_400f0a50(auStack_44);
  FUN_400f0be8(auStack_44,"_update");
  puStack_28 = (undefined *)0x400e0898;
  pcStack_2c = (code *)&LAB_401840bc;
  auStack_34[0] = param_1;
  FUN_400e0bf4(param_1,auStack_44,auStack_34);
  (*(code *)&LAB_40183a17_1)(auStack_34);
  FUN_400f0a50(auStack_44);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    do {
      (*(code *)&LAB_40183a17_1)(auStack_34);
      FUN_400f0a50(auStack_44);
      thunk_FUN_401710d8(iVar1);
    } while( true );
  }
  return;
}

