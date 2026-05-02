// Function : FUN_4015d540
// Address  : 0x4015d540
// Size     : 74 bytes


void FUN_4015d540(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = *(uint **)(param_1 + 0x2c);
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
  if ((*puVar1 & 0x40000) != 0) {
    iVar2 = iVar2 + 4;
  }
  iVar2 = FUN_4015c820(iVar2 + 0x10);
  if (iVar2 != 0) {
    if (*(char *)((int)puVar1 + 0x13) == '\x01') {
      *(undefined1 *)(iVar2 + 0xa9) = 5;
      memw();
      memw();
    }
    else {
      FUN_4015d4e8(iVar2,0xfffffffd,1);
    }
  }
  iVar2 = FUN_4015b634();
  if (iVar2 != 0) {
    FUN_4015b934(iVar2,0);
    return;
  }
  FUN_4015b674(0,0);
  return;
}

