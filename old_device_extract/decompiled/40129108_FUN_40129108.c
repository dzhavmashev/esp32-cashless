// Function : FUN_40129108
// Address  : 0x40129108
// Size     : 54 bytes


undefined4 FUN_40129108(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 1;
  if (*(uint *)(param_1 + 0xa8) <= *(uint *)(param_1 + 0x84)) {
    iVar3 = *(int *)(param_1 + 0x78);
    iVar2 = (*(code *)&SUB_4008b33c)(iVar3 + 6,&DAT_3f41aa5d,3);
    uVar1 = 1;
    if (iVar2 == 0) {
      iVar2 = (*(code *)&SUB_4008b33c)(iVar3 + 9,iVar3 + 1,3);
      uVar1 = 1;
      if (iVar2 == 0) {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

