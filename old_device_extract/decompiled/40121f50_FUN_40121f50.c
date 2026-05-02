// Function : FUN_40121f50
// Address  : 0x40121f50
// Size     : 79 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40121f50(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400f8eb4(1,3,0);
  if (iVar1 == 0) {
    uVar2 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc0d43,uVar2,0x3ffc0d6d);
  }
  else {
    _DAT_3ffc7250 = *(undefined4 *)(iVar1 + 0xc);
    _DAT_3ffc7254 = *(undefined4 *)(iVar1 + 0x10);
    DAT_3ffc7258 = *(undefined1 *)(iVar1 + 0x25);
    memw();
    memw();
    _DAT_3ffc725c = (*(code *)&SUB_4005cfec)(0,&DAT_3ffc7250,0xc);
    memw();
  }
  return;
}

