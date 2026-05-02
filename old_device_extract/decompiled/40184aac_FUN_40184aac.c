// Function : FUN_40184aac
// Address  : 0x40184aac
// Size     : 124 bytes


int FUN_40184aac(int param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 auStack_24 [9];
  
  if ((param_2 < param_3) && (param_3 < 0x7f)) {
    param_3 = param_3 - 1;
    uVar3 = param_3 >> 4;
    for (; (int)param_2 <= (int)param_3; param_3 = param_3 - 1) {
      iVar2 = param_1 + (param_3 >> 4) * 4;
      uVar1 = 0xffffffff;
      *(uint *)(iVar2 + 0x18) =
           (3 << 0x20 - ((param_3 & 0xf) * -2 + 0x20) ^ 0xffffffffU) & *(uint *)(iVar2 + 0x18) |
           param_4 << 0x20 - ((param_3 & 0xf) * -2 + 0x20);
      if (param_2 != param_3) {
        uVar1 = param_3 - 1 >> 4;
      }
      if (uVar3 != uVar1) {
        auStack_24[0] = *(undefined4 *)(param_1 + uVar3 * 4 + 0x18);
        memw();
        iVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                          (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x20 + uVar3 * 4,
                           auStack_24,4);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      uVar3 = uVar1;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

