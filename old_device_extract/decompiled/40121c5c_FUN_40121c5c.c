// Function : FUN_40121c5c
// Address  : 0x40121c5c
// Size     : 172 bytes


int FUN_40121c5c(int *param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint auStack_24 [9];
  
  auStack_24[0] = 0;
  memw();
  iVar1 = FUN_400f8eb4(1,3,0);
  if (iVar1 == 0) {
    uVar2 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc0adf,uVar2,0x3ffc0d6d);
    iVar1 = 0x105;
  }
  else {
    if (*(uint *)(iVar1 + 0x10) < 4) {
      uVar2 = (*(code *)&SUB_40094ae8)();
      (*(code *)&SUB_40007d54)(0x3ffc0ab4,uVar2,0x3ffc0d6d);
    }
    else {
      iVar3 = FUN_400f90c0(iVar1,0,auStack_24,4);
      if (iVar3 != 0) {
        uVar2 = (*(code *)&SUB_40094ae8)();
        (*(code *)&SUB_40007d54)(0x3ffc0a7f,uVar2,0x3ffc0d6d,iVar3);
        return iVar3;
      }
      if (auStack_24[0] != 0xffffffff) {
        if ((3 < auStack_24[0]) && (auStack_24[0] <= *(uint *)(iVar1 + 0x10))) {
          *param_1 = iVar1;
          *param_2 = auStack_24[0];
          memw();
          return 0;
        }
        uVar2 = (*(code *)&SUB_40094ae8)();
        (*(code *)&SUB_40007d54)(0x3ffc0a4d,uVar2,0x3ffc0d6d,auStack_24[0]);
      }
    }
    iVar1 = 0x104;
  }
  return iVar1;
}

