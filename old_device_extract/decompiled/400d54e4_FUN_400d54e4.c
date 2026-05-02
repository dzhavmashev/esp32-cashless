// Function : FUN_400d54e4
// Address  : 0x400d54e4
// Size     : 133 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d54e4(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *apuStack_88 [4];
  undefined1 uStack_78;
  int iStack_74;
  int iStack_70;
  char cStack_6c;
  undefined1 uStack_6b;
  undefined4 *puStack_68;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  piVar3 = param_2;
  piVar2 = param_2;
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) goto LAB_400d5562;
  while( true ) {
    iStack_70 = (*(code *)&LAB_40183a7b_1)(piVar2);
    param_1[1] = *param_1;
    iStack_70 = (int)piVar3 + iStack_70;
    param_1[2] = param_1[3];
    *(undefined1 *)(param_1 + 4) = 0;
    *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) & 0x80;
    uStack_78 = 0;
    uStack_6b = 0;
    apuStack_88[0] = param_1;
    iStack_74 = (int)piVar3;
    puStack_68 = param_1;
    puVar1 = (undefined4 *)FUN_400d5314(apuStack_88,param_1 + 6,0,10);
    if (((puVar1 == (undefined4 *)0x0) && (cStack_6c != '\0')) &&
       ((*(byte *)(param_1 + 8) >> 3 & 1) != 0)) {
      puVar1 = (undefined4 *)0x3;
    }
    param_1 = puVar1;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    piVar2 = (int *)func_0x40082ecc();
LAB_400d5562:
    piVar3 = (int *)*param_2;
  }
  return;
}

