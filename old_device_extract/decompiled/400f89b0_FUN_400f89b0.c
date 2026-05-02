// Function : FUN_400f89b0
// Address  : 0x400f89b0
// Size     : 362 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400f89b0(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uStack_4c;
  int local_48;
  undefined1 auStack_44 [32];
  int iStack_24;
  
  iVar5 = 0x102;
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_4c = 0xef;
  local_48 = 0;
  if (param_3 != 0) {
    if ((uint)param_2[1] < 0x1000001) {
      iVar3 = *param_2;
      bVar1 = param_1 == 1;
      piVar6 = (int *)0x0;
      if (iVar3 != 0x1000) {
        piVar6 = &local_48;
      }
      iVar5 = FUN_400f867c(param_3,iVar3,piVar6,1,bVar1);
      if ((iVar5 == 0) && (iVar5 = FUN_400f87b4(param_3,bVar1,local_48,&uStack_4c), iVar5 == 0)) {
        uVar2 = (*(code *)&SUB_400842b0)();
        iVar5 = FUN_400f85a4(local_48,uStack_4c,param_3,bVar1,uVar2);
        if ((iVar5 == 0) && (iVar5 = FUN_400f8758(param_3,param_2[1],bVar1), iVar5 == 0)) {
          if (((iVar3 != 0x1000) && (local_48 != 0)) &&
             (iVar4 = (*(code *)&SUB_400842b0)(), iVar3 = local_48, iVar4 == 0)) {
            (*(code *)&SUB_4008b530)(auStack_44,0,0x20);
            FUN_400f8b80(iVar3,auStack_44);
            FUN_401848cc(auStack_44,0x20,"n 16MB\n");
            iVar3 = (*(code *)&SUB_4008b33c)(param_3 + 0xe0,auStack_44,0x20);
            iVar5 = 0;
            if (iVar3 != 0) {
              uVar2 = (*(code *)&SUB_40094b80)();
              FUN_4012113c(1,"_common","ed hash",uVar2,"_common");
              FUN_401848cc(param_3 + 0xe0,0x20,"orrupt\n");
              iVar5 = 0x2002;
            }
            local_48 = 0;
          }
          if (local_48 != 0) {
            memw();
            FUN_400f8b80(local_48,0);
            local_48 = 0;
          }
          if (iVar5 == 0) goto LAB_400f8afc;
        }
      }
    }
    else if (param_1 != 1) {
      memw();
      uVar2 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"_common","rapped\n",uVar2,"_common",param_2[1]);
      iVar5 = 0x102;
    }
    if (local_48 != 0) {
      FUN_400f8b80(local_48,0);
    }
    (*(code *)&SUB_4008b530)(param_3,0,0x104);
  }
LAB_400f8afc:
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    memw();
    (*(code *)&SUB_40082ec4)();
  }
  return iVar5;
}

