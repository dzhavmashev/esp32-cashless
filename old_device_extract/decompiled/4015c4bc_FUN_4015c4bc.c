// Function : FUN_4015c4bc
// Address  : 0x4015c4bc
// Size     : 136 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015c4bc(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  memw();
  FUN_40147fe4(1,4,4,0x3f4345d5,*param_1,param_1[1],param_1[2],param_1[3],param_1[4],param_1[5],
               DAT_3ffca0b4);
  iVar4 = _DAT_3ffca0b0;
  iVar2 = 0;
  do {
    iVar3 = iVar2;
    iVar2 = iVar4;
    if (iVar2 == 0) {
      return;
    }
    iVar1 = (*(code *)&SUB_4008b33c)(param_1,iVar2,6);
    iVar4 = *(int *)(iVar2 + 8);
  } while (iVar1 != 0);
  if (iVar3 != 0) {
    *(int *)(iVar3 + 8) = iVar4;
    memw();
    iVar4 = _DAT_3ffca0b0;
  }
  _DAT_3ffca0b0 = iVar4;
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar2);
  DAT_3ffca0b4 = DAT_3ffca0b4 + -1;
  memw();
  memw();
  return;
}

