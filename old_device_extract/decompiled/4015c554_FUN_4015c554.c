// Function : FUN_4015c554
// Address  : 0x4015c554
// Size     : 169 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015c554(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  memw();
  FUN_40147fe4(1,4,4,0x3f434598,*param_1,param_1[1],param_1[2],param_1[3],param_1[4],param_1[5],
               DAT_3ffca0b4);
  iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x16c))(0xc);
  if (iVar2 == 0) {
    FUN_40147fe4(1,4,2,0x3f436d09);
    return;
  }
  (*(code *)&SUB_4008b3d0)(iVar2,param_1,6);
  *(undefined4 *)(iVar2 + 8) = 0;
  iVar1 = _DAT_3ffca0b0;
  if (_DAT_3ffca0b0 == 0) {
    memw();
  }
  else {
    iVar3 = FUN_4015c48c(param_1);
    if (iVar3 != 0) {
      FUN_40147fe4(1,4,4,0x3f434583);
      (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar2);
      return;
    }
    *(int *)(iVar2 + 8) = iVar1;
  }
  _DAT_3ffca0b0 = iVar2;
  DAT_3ffca0b4 = DAT_3ffca0b4 + '\x01';
  memw();
  memw();
  return;
}

