// Function : FUN_400daa1c
// Address  : 0x400daa1c
// Size     : 79 bytes


void FUN_400daa1c(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  iVar1 = FUN_400f1a9c();
  puVar2 = *(undefined2 **)(param_1 + 0x830);
  while (puVar2 != *(undefined2 **)(param_1 + 0x834)) {
    if ((uint)(iVar1 - *(int *)(puVar2 + 10)) < 0x2711) {
      puVar2 = puVar2 + 0xc;
    }
    else {
      puVar3 = puVar2 + 2;
      if ((*(byte *)((int)puVar2 + 0x13) & 0x80) == 0) {
        puVar3 = *(undefined2 **)(puVar2 + 2);
      }
      FUN_400f06a4(0x3ffc5490,"%lums)\n",puVar3,*puVar2);
      puVar2 = (undefined2 *)FUN_400da974(param_1 + 0x830,puVar2);
    }
  }
  return;
}

