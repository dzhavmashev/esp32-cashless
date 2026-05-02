// Function : FUN_4014ebe0
// Address  : 0x4014ebe0
// Size     : 284 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014ebe0(uint param_1)

{
  byte bVar1;
  int iVar2;
  
  if (((uint)DAT_3ffc8a35 & 1 << ((byte)param_1 & 0x1f)) != 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423b50,0x64c);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (((uint)DAT_3ffc8a36 & 1 << ((byte)param_1 & 0x1f)) != 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423b50,0x64d);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (DAT_3ffc8a35 == 0) {
    FUN_4015182c();
    (**(code **)(_DAT_3ffc1a34 + 200))();
    (**(code **)(_DAT_3ffc1a34 + 0x100))();
    if (DAT_3ffc79a6 != '\0') {
      (**(code **)(_DAT_3ffc1a34 + 0x10c))();
    }
    (**(code **)(_DAT_3ffc1a34 + 0xd4))();
    (**(code **)(_DAT_3ffc1a34 + 0x18c))();
    FUN_4014eb80();
    FUN_4018ba74();
    FUN_4015b374(&DAT_3ffc87f0);
    FUN_4015ff3c();
    FUN_4014eb30();
    FUN_401612e4();
LAB_4014ecaf:
    if (param_1 != 0) {
      if (DAT_3ffc8a35 == 0) {
        FUN_40162224();
        iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
        if (iVar2 != 0) {
          FUN_4016221c();
        }
      }
      goto LAB_4014ecd4;
    }
  }
  else {
    if (DAT_3ffc8a36 == 0) {
      (**(code **)(_DAT_3ffc1a34 + 200))();
      (**(code **)(_DAT_3ffc1a34 + 0x100))();
      if (DAT_3ffc79a6 != '\0') {
        FUN_4016143c();
      }
      iVar2 = (**(code **)(_DAT_3ffc1a34 + 4))();
      if (iVar2 != 0) {
        (**(code **)(_DAT_3ffc1a34 + 0xd4))();
      }
      FUN_4018ba74();
      goto LAB_4014ecaf;
    }
    if (param_1 != 0) goto LAB_4014ecd4;
  }
  FUN_40162300();
LAB_4014ecd4:
  bVar1 = (byte)(1 << 0x20 - (0x20 - (param_1 & 0x1f)));
  DAT_3ffc8a35 = bVar1 | DAT_3ffc8a35;
  memw();
  DAT_3ffc8a36 = bVar1 | DAT_3ffc8a36;
  memw();
  memw();
  return;
}

