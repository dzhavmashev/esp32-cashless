// Function : FUN_4018b860
// Address  : 0x4018b860
// Size     : 117 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018b860(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if (((uint)DAT_3ffc8a36 & 1 << ((byte)param_1 & 0x1f)) == 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423b50,0x638);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar1 = (uint)DAT_3ffc8a36 & (uint)(0xfffffffefffffffe >> 0x20 - (param_1 & 0x1f));
  DAT_3ffc8a36 = (byte)uVar1;
  memw();
  if (uVar1 == 0) {
    memw();
    FUN_4018ba80();
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 4))();
    if (iVar2 != 0) {
      (**(code **)(_DAT_3ffc1a34 + 0xd0))();
    }
    if (DAT_3ffc79a6 != '\0') {
      FUN_40161444();
    }
    (**(code **)(_DAT_3ffc1a34 + 0x104))();
    (**(code **)(_DAT_3ffc1a34 + 0xcc))();
  }
  return;
}

