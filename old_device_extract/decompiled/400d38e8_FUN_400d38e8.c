// Function : FUN_400d38e8
// Address  : 0x400d38e8
// Size     : 233 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d38e8(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  undefined1 auStack_8a8 [2180];
  int *local_24;
  
  memw();
  memw();
  local_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"nager: ");
  FUN_400dba6c(auStack_8a8);
  iVar1 = FUN_400daa6c(auStack_8a8,param_2);
  piVar3 = (int *)0x3ffc5490;
  if (iVar1 != 0) goto LAB_400d3969;
  FUN_400f0780(0x3ffc5490,"nection");
  FUN_400f0d70(param_1 + 4,"idation");
  uVar2 = 0xfffffff6;
  iVar1 = 0;
  do {
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    param_1 = iVar1;
    while( true ) {
      FUN_400dbc30(auStack_8a8);
      piVar3 = local_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (local_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
LAB_400d3969:
      piVar4 = param_2;
      if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
        piVar4 = (int *)*param_2;
      }
      FUN_400f06a4(piVar3,"uration",piVar4,param_2[4]);
      iVar1 = FUN_400daf88(auStack_8a8);
      if (iVar1 == 0) break;
      FUN_400f0780(piVar3," %s:%d\n");
      FUN_400db4c0(auStack_8a8);
      param_1 = iVar1;
    }
    FUN_400f0780(piVar3,"cessful");
    FUN_400f0d70(param_1 + 4," failed");
    uVar2 = 0xfffffff5;
  } while( true );
}

