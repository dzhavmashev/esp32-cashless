// Function : FUN_400f7f24
// Address  : 0x400f7f24
// Size     : 54 bytes


int FUN_400f7f24(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + param_3 * 0x20);
  *puVar3 = param_2;
  memw();
  uVar1 = FUN_400f8354(puVar3);
  puVar3[7] = uVar1;
  memw();
  iVar2 = FUN_400f9018(param_4,param_3 << 0xc,0x1000);
  if (iVar2 == 0) {
    iVar2 = FUN_400f8f44(param_4,param_3 << 0xc,puVar3,0x20);
  }
  return iVar2;
}

