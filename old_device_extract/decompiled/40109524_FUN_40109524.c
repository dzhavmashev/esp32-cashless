// Function : FUN_40109524
// Address  : 0x40109524
// Size     : 132 bytes


undefined4 FUN_40109524(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 auStack_24 [9];
  
  puVar3 = (undefined4 *)FUN_40108224(param_1);
  if (puVar3 != (undefined4 *)0x0) {
    if ((*(uint *)*puVar3 & 0xf0) != 0x10) {
      FUN_40108194(puVar3);
      uVar4 = FUN_401093b0(param_1,param_2,param_3,param_4,0);
      return uVar4;
    }
    bVar1 = 1;
    if ((param_4 & 0x10) != 0) {
      bVar1 = 3;
    }
    auStack_24[0] = 0;
    memw();
    cVar2 = FUN_4011c330((uint *)*puVar3,param_2,param_3,(byte)((int)param_4 >> 1) & 4 | bVar1,
                         auStack_24);
    iVar5 = FUN_4011d9e4((int)cVar2);
    if (iVar5 != 0) {
      piVar6 = (int *)FUN_40173a8c();
      *piVar6 = iVar5;
    }
    memw();
    FUN_40108194(puVar3);
    if (cVar2 == '\0') {
      return auStack_24[0];
    }
  }
  return 0xffffffff;
}

