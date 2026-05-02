// Function : FUN_40109af0
// Address  : 0x40109af0
// Size     : 159 bytes


undefined4 FUN_40109af0(undefined4 param_1,int param_2,int *param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  piVar2 = (int *)FUN_40108224(param_1);
  if (piVar2 == (int *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == -0x7ffb9982) {
    bVar1 = *(byte *)(*piVar2 + 0x34);
    if ((param_3 == (int *)0x0) || (*param_3 == 0)) {
      bVar1 = bVar1 & 0xfd;
    }
    else {
      bVar1 = bVar1 | 2;
    }
    *(byte *)(*piVar2 + 0x34) = bVar1;
    memw();
    memw();
LAB_40109b50:
    memw();
    FUN_40108194(piVar2);
    uVar6 = 0;
  }
  else {
    if (param_2 == 0x4004667f) {
      if (param_3 != (int *)0x0) {
        FUN_4011b020();
        iVar3 = *(int *)(*piVar2 + 0x30);
        FUN_4011b040();
        iVar3 = (uint)(-1 < iVar3) * iVar3;
        piVar4 = (int *)piVar2[1];
        if (piVar4 != (int *)0x0) {
          if ((*(uint *)*piVar2 & 0xf0) != 0x10) {
            piVar4 = (int *)*piVar4;
          }
          iVar3 = iVar3 + (uint)*(ushort *)(piVar4 + 2);
        }
        *param_3 = iVar3;
        goto LAB_40109b50;
      }
      puVar5 = (undefined4 *)FUN_40173a8c();
      uVar6 = 0x16;
    }
    else {
      puVar5 = (undefined4 *)FUN_40173a8c();
      uVar6 = 0x58;
    }
    *puVar5 = uVar6;
    memw();
    FUN_40108194(piVar2);
    uVar6 = 0xffffffff;
  }
  return uVar6;
}

