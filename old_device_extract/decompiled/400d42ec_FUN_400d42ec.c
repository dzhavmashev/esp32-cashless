// Function : FUN_400d42ec
// Address  : 0x400d42ec
// Size     : 48 bytes


undefined8 FUN_400d42ec(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iStack_2c;
  int iStack_28;
  
  iVar5 = *param_1;
  iVar3 = param_1[2];
  iVar1 = *(int *)(iVar5 + 4);
  iStack_2c = iVar1;
  iStack_28 = iVar3;
  iVar2 = FUN_40183b74(iVar5,&iStack_2c);
  if (iVar2 == 0) {
    puVar4 = (undefined1 *)(iVar1 + iVar3);
    *(undefined1 **)(iVar5 + 4) = puVar4 + 1;
    *puVar4 = 0;
    iVar2 = iVar1;
  }
  return CONCAT44(param_1[2],iVar2);
}

