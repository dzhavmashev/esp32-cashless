// Function : FUN_4012d840
// Address  : 0x4012d840
// Size     : 205 bytes


int FUN_4012d840(int *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = 0;
  if (param_1[5] != 0) {
    iVar2 = 2;
  }
  param_4 = param_1[0x11] + 0x4b0 + param_4;
  uVar3 = iVar2 + param_2;
  iVar6 = -0x6a00;
  if (uVar3 < 0x4001) {
    puVar4 = (undefined1 *)*param_1;
    FUN_401858e4(*puVar4,puVar4[1],puVar4[5],param_4);
    iVar6 = (**(code **)(*param_1 + 0x4c))(*(undefined4 *)(*param_1 + 0x50),param_4 + 2,0x2e);
    if (iVar6 == 0) {
      *(undefined4 *)(param_1[0x11] + 0x10) = 0x30;
      iVar6 = -0x6c00;
      if (*(int *)(param_1[0x10] + 100) != 0) {
        iVar5 = *(int *)(param_1[0x10] + 100) + 0xcc;
        memw();
        iVar1 = FUN_401864ec(iVar5,1);
        iVar6 = -0x6d00;
        if (iVar1 != 0) {
          memw();
          iVar6 = FUN_40139cb0(iVar5,param_4,*(undefined4 *)(param_1[0x11] + 0x10),
                               param_1[0x33] + uVar3,param_3,0x4000 - uVar3,
                               *(undefined4 *)(*param_1 + 0x4c),*(undefined4 *)(*param_1 + 0x50));
          if ((iVar6 == 0) && (iVar2 == 2)) {
            *(char *)(param_1[0x33] + param_2) = (char)((uint)*param_3 >> 8);
            memw();
            *(char *)(param_1[0x33] + param_2 + 1) = (char)*param_3;
            memw();
            *param_3 = *param_3 + 2;
          }
        }
      }
    }
  }
  memw();
  return iVar6;
}

