// Function : FUN_4011b428
// Address  : 0x4011b428
// Size     : 118 bytes


void FUN_4011b428(void)

{
  int iVar1;
  undefined1 auStack_c4 [4];
  undefined4 uStack_c0;
  undefined4 uStack_b8;
  undefined *puStack_a8;
  undefined1 *puStack_a4;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined *puStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  (*(code *)&SUB_4008b530)(auStack_c4,0,0xa4);
  uStack_c0 = 0x4010964c;
  uStack_b8 = 0x40109370;
  puStack_a8 = &DAT_401090ac;
  puStack_a4 = &LAB_4011b3e0;
  uStack_70 = 0x4011b3d0;
  uStack_6c = 0x4011b398;
  puStack_34 = &DAT_40109664;
  uStack_30 = 0x4011b38c;
  uStack_2c = 0x4011b374;
  uStack_28 = 0x4011b368;
  memw();
  iVar1 = FUN_400fe980(auStack_c4,0,0x30,0x40);
  if (iVar1 != 0) {
    (*(code *)&SUB_4008effc)(iVar1,"AX_FDS)",0x6c,"_lwip.c","if_init");
  }
  return;
}

