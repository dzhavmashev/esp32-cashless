// Function : FUN_400f0a5c
// Address  : 0x400f0a5c
// Size     : 257 bytes


/* WARNING: Removing unreachable block (ram,0x400f0acb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f0a5c(int *param_1,uint param_2)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_33 [15];
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  if (0xd < param_2) {
    uVar2 = param_2 + 0x10 & 0xfffffff0;
    if (uVar2 < 0x300001) goto LAB_400f0afd;
    goto LAB_400f0ae8;
  }
  if (((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) && (iVar3 = *param_1, iVar3 != 0)) {
    func_0x4008b3d8(auStack_33,iVar3,param_2);
    func_0x40094d88(iVar3);
    uVar1 = FUN_40184778(param_1);
    *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) | 0x80;
    func_0x4008b3d8(param_1,auStack_33,param_2);
  }
  else {
    uVar1 = FUN_40184778(param_1);
    *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) | 0x80;
  }
  do {
    FUN_40184790(param_1,uVar1);
    param_1 = (int *)0x1;
    while( true ) {
      uVar2 = _DAT_3ffc5708;
      memw();
      memw();
      if (uStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
LAB_400f0afd:
      uVar1 = FUN_40184778(param_1);
      iVar3 = 0;
      if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
        iVar3 = *param_1;
      }
      iVar3 = func_0x40094d74(iVar3,uVar2);
      if (iVar3 != 0) break;
LAB_400f0ae8:
      param_1 = (int *)0x0;
    }
    iVar4 = 0xe;
    if (-1 < *(char *)((int)param_1 + 0xf)) {
      iVar4 = param_1[1];
    }
    uVar5 = iVar4 + 1;
    if (*(char *)((int)param_1 + 0xf) < '\0') {
      func_0x4008b4d0(iVar3,param_1,0xf);
    }
    if (uVar5 < uVar2) {
      func_0x4008b538(iVar3 + uVar5,0,uVar2 - uVar5);
    }
    *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0x7f;
    param_1[1] = uVar2 - 1;
    *param_1 = iVar3;
  } while( true );
}

