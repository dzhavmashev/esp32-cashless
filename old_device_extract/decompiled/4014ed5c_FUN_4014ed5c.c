// Function : FUN_4014ed5c
// Address  : 0x4014ed5c
// Size     : 248 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014ed5c(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (((uint)DAT_3ffc8a35 & 1 << ((byte)param_1 & 0x1f)) == 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423b50,0x695);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (((uint)DAT_3ffc8a36 & 1 << ((byte)param_1 & 0x1f)) == 0) {
    FUN_40147fe4(1,0x800,1,"be NULL",&DAT_3f423b50,0x696);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar2 = (1 << 0x20 - (0x20 - (param_1 & 0x1f)) ^ 0xffffffffU) & 0xff;
  uVar3 = DAT_3ffc8a35 & uVar2;
  uVar2 = DAT_3ffc8a36 & uVar2;
  DAT_3ffc8a35 = (byte)uVar3;
  DAT_3ffc8a36 = (byte)uVar2;
  memw();
  if (uVar3 == 0) {
    memw();
    FUN_4015182c();
    FUN_401612d0();
    FUN_4014ed2c();
    FUN_4014eb50();
    FUN_4015ff70();
    FUN_4015b0b8();
    FUN_4018ba80();
    (**(code **)(_DAT_3ffc1a34 + 400))();
    (**(code **)(_DAT_3ffc1a34 + 0xd0))();
    if (DAT_3ffc79a6 != '\0') {
      (**(code **)(_DAT_3ffc1a34 + 0x108))();
    }
    (**(code **)(_DAT_3ffc1a34 + 0x104))();
    (**(code **)(_DAT_3ffc1a34 + 0xcc))();
    FUN_40160084();
  }
  else if (uVar2 == 0) {
    FUN_4018ba80();
    iVar1 = (**(code **)(_DAT_3ffc1a34 + 4))();
    if (iVar1 != 0) {
      (**(code **)(_DAT_3ffc1a34 + 0xd0))();
    }
    if (DAT_3ffc79a6 != '\0') {
      FUN_40161444();
    }
    (**(code **)(_DAT_3ffc1a34 + 0x104))();
    (**(code **)(_DAT_3ffc1a34 + 0xcc))();
  }
  if (param_1 == 0) {
    FUN_40162358();
  }
  return;
}

