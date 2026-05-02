// Function : FUN_401715b8
// Address  : 0x401715b8
// Size     : 184 bytes


int FUN_401715b8(uint *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint local_40 [4];
  uint uStack_30;
  undefined4 uStack_2c;
  
  uVar7 = 0;
  uVar3 = 0;
  iVar4 = 0;
  iVar6 = 0;
  do {
    if (*param_2 == 0) {
      return iVar4;
    }
    iVar2 = iVar6;
    if (param_2[1] != 0) {
      iVar2 = (int)param_2 + (4 - param_2[1]);
      if (iVar6 != iVar2) {
        uVar3 = FUN_40171528(iVar2);
        if (uVar3 == 0xff) {
          return -1;
        }
        uVar7 = FUN_401713c4(uVar3 & 0xff,param_1);
        uVar5 = param_1[4];
        if ((uVar5 & 0x7f8) == 0x7f8) {
          uVar5 = uVar5 & 0xfffff807 | (uVar3 & 0xff) << 3;
        }
        else {
          if ((uVar5 >> 3 & 0xff) == uVar3) goto LAB_4017161d;
          uVar5 = uVar5 | 4;
        }
        param_1[4] = uVar5;
      }
LAB_4017161d:
      uStack_30 = uVar3 & 0xff;
      uStack_2c = uVar7;
      FUN_40171410(uStack_30,uVar7,param_2 + 2,local_40);
      uVar1 = FUN_4017138c(uStack_30);
      uVar5 = 0xffffffff;
      if (uVar1 < 4) {
        uVar5 = (1 << 0x20 - ((uVar1 & 3) * -8 + 0x20)) - 1;
      }
      uVar7 = uStack_2c;
      if (((local_40[0] & uVar5) != 0) && (iVar4 = iVar4 + 1, local_40[0] < *param_1)) {
        *param_1 = local_40[0];
      }
    }
    param_2 = (int *)((int)param_2 + *param_2 + 4);
    iVar6 = iVar2;
  } while( true );
}

