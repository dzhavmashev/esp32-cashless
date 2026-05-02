// Function : FUN_401299ec
// Address  : 0x401299ec
// Size     : 112 bytes


void FUN_401299ec(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_1[0x11];
  if ((param_1[1] != 0x10) && (iVar1 != 0)) {
    (**(code **)(iVar1 + 0x18))(param_1,param_1[0x1e],param_1[0x2a]);
  }
  if ((*(char *)(*param_1 + 5) == '\x01') && (param_1[0x11] != 0)) {
    *(int *)(iVar1 + 0x23c) = *(int *)(iVar1 + 0x23c) + 1;
    memw();
    FUN_40129090(param_1,0);
    puVar2 = (undefined4 *)(iVar1 + 0x1fc);
    while (puVar2 != (undefined4 *)(iVar1 + 0x220)) {
      *puVar2 = puVar2[3];
      puVar2[1] = puVar2[4];
      puVar2[2] = puVar2[5];
      memw();
      puVar2 = puVar2 + 3;
    }
    (*(code *)&SUB_4008b530)(iVar1 + 0x220,0,0xc);
  }
  return;
}

