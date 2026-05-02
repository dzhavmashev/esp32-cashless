// Function : FUN_4018b7dc
// Address  : 0x4018b7dc
// Size     : 124 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018b7dc(uint param_1)

{
  int iVar1;
  
  if (((uint)DAT_3ffc8a36 & 1 << ((byte)param_1 & 0x1f)) != 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423b50,0x624);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (DAT_3ffc8a36 == 0) {
    (**(code **)(_DAT_3ffc1a34 + 200))();
    (**(code **)(_DAT_3ffc1a34 + 0x100))();
    if (DAT_3ffc79a6 != '\0') {
      FUN_4016143c();
    }
    iVar1 = (**(code **)(_DAT_3ffc1a34 + 4))();
    if (iVar1 != 0) {
      (**(code **)(_DAT_3ffc1a34 + 0xd4))();
    }
    FUN_4018ba74();
  }
  DAT_3ffc8a36 = (byte)(1 << 0x20 - (0x20 - (param_1 & 0x1f))) | DAT_3ffc8a36;
  memw();
  memw();
  return;
}

