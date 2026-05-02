// Function : FUN_40163960
// Address  : 0x40163960
// Size     : 189 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163960(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  (*(code *)&SUB_4008b530)(0x3ffc1b5c,0,0x1e);
  (*(code *)&SUB_4008b530)(0x3ffc1acc,0,0x90);
  (*(code *)&SUB_4008b530)(0x3ffc0038,0,0x3c0);
  *(undefined4 *)(_DAT_3ffc0034 + 0x3b8) = 0x640;
  memw();
  FUN_40186b98();
  FUN_40163480();
  iVar2 = _DAT_3ffc0034;
  *(int *)(_DAT_3ffc0034 + 0x338) = _DAT_3ffc0034 + 0x334;
  *(undefined4 *)(iVar2 + 0x334) = 0;
  *(undefined4 *)(iVar2 + 0x33c) = 0;
  *(int *)(iVar2 + 0x340) = iVar2 + 0x33c;
  *(undefined4 *)(iVar2 + 0x344) = 0;
  *(undefined4 *)(iVar2 + 0x34c) = 0;
  *(int *)(iVar2 + 0x348) = iVar2 + 0x344;
  *(int *)(iVar2 + 0x350) = iVar2 + 0x34c;
  memw();
  iVar2 = FUN_4015f7f0(param_1);
  if (iVar2 == 0) {
    iVar2 = 0;
    do {
      iVar1 = _DAT_3ffc0034;
      uVar3 = FUN_401638a4(iVar2);
      iVar4 = iVar2 + 200;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iVar4 * 4 + iVar1) = uVar3;
      iVar1 = _DAT_3ffc0034;
    } while (iVar2 != 4);
    *(undefined1 *)(_DAT_3ffc0034 + 0x358) = 0;
    *(undefined1 *)(iVar1 + 0x1d) = 1;
    *(undefined4 *)(iVar1 + 0x330) = 0;
    *(undefined1 *)(iVar1 + 0x359) = 1;
    *(undefined1 *)(iVar1 + 0x1e) = 0;
    memw();
    memw();
    return;
  }
  FUN_401633c4();
  return;
}

