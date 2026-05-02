// Function : FUN_40171674
// Address  : 0x40171674
// Size     : 177 bytes


int * FUN_40171674(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint local_40;
  uint auStack_3c [3];
  uint uStack_30;
  undefined4 uStack_2c;
  
  uVar4 = *(uint *)(param_1 + 0x10) >> 3 & 0xff;
  uVar2 = FUN_401713c4(uVar4,param_1);
  iVar6 = 0;
  do {
    if (*param_2 == 0) {
      return (int *)0x0;
    }
    if (param_2[1] != 0) {
      if (((*(uint *)(param_1 + 0x10) & 4) != 0) &&
         (iVar5 = (int)param_2 + (4 - param_2[1]), bVar1 = iVar6 != iVar5, iVar6 = iVar5, bVar1)) {
        uVar4 = FUN_40171528(iVar5);
        uVar2 = FUN_401713c4(uVar4 & 0xff,param_1);
      }
      if (uVar4 == 0) {
        auStack_3c[0] = param_2[2];
        local_40 = param_2[3];
        uVar3 = auStack_3c[0];
      }
      else {
        uStack_30 = uVar4 & 0xff;
        uStack_2c = uVar2;
        uVar2 = FUN_40171410(uStack_30,uVar2,param_2 + 2,auStack_3c);
        FUN_40171410(uVar4 & 0xf,0,uVar2,&local_40);
        uVar3 = FUN_4017138c(uStack_30);
        uVar7 = 0xffffffff;
        if (uVar3 < 4) {
          uVar7 = (1 << 0x20 - ((uVar3 & 3) * -8 + 0x20)) - 1;
        }
        uVar2 = uStack_2c;
        uVar3 = uVar7 & auStack_3c[0];
      }
      if ((uVar3 != 0) && (param_3 - auStack_3c[0] < local_40)) {
        return param_2;
      }
    }
    param_2 = (int *)((int)param_2 + *param_2 + 4);
  } while( true );
}

