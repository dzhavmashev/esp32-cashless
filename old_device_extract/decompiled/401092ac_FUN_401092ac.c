// Function : FUN_401092ac
// Address  : 0x401092ac
// Size     : 200 bytes


int FUN_401092ac(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4,int param_5,
                undefined4 *param_6)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  ushort uStack_46;
  uint local_44;
  uint uStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  uint *puStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  memw();
  puVar2 = (undefined4 *)FUN_40108224(param_1);
  iVar3 = -1;
  if (puVar2 != (undefined4 *)0x0) {
    if ((*(uint *)*puVar2 & 0xf0) == 0x10) {
      iVar3 = FUN_40107ac4(puVar2,param_2,param_3,param_4);
      if ((param_5 != 0) && (param_6 != (undefined4 *)0x0)) {
        FUN_4011c104(*puVar2,&iStack_3c,&local_44,0);
        FUN_401078c8(*puVar2,&iStack_3c,local_44 & 0xffff,param_5,param_6);
      }
    }
    else {
      uStack_46 = 0;
      memw();
      puStack_34 = &local_44;
      uStack_38 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_30 = 1;
      if (param_6 != (undefined4 *)0x0) {
        uStack_38 = *param_6;
      }
      memw();
      local_44 = param_2;
      uStack_40 = param_3;
      iStack_3c = param_5;
      cVar1 = FUN_401080a8(puVar2,param_4,&iStack_3c,&uStack_46);
      if (cVar1 != '\0') {
        iVar3 = FUN_4011d9e4((int)cVar1);
        if (iVar3 != 0) {
          piVar4 = (int *)FUN_40173a8c();
          *piVar4 = iVar3;
        }
        memw();
        FUN_40108194(puVar2);
        return -1;
      }
      uVar5 = (uint)uStack_46;
      iVar3 = (uVar5 < param_3) * uVar5 + (uVar5 >= param_3) * param_3;
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = uStack_38;
        memw();
      }
    }
    FUN_40108194(puVar2);
  }
  return iVar3;
}

