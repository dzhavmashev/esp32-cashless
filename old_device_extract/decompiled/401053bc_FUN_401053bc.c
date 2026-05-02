// Function : FUN_401053bc
// Address  : 0x401053bc
// Size     : 143 bytes


void FUN_401053bc(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int aiStack_24 [9];
  
  puVar1 = (undefined2 *)(*(code *)&SUB_40094d60)(param_3 + 0x80);
  if (puVar1 != (undefined2 *)0x0) {
    aiStack_24[0] = 0;
    memw();
    iVar2 = FUN_4015aac0(0);
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar2 = FUN_4014750c(2,aiStack_24);
      *(bool *)(puVar1 + 1) = iVar2 == 0 && aiStack_24[0] != 0;
      *(undefined1 *)((int)puVar1 + 3) = 0;
      *puVar1 = 0x37f;
      iVar3 = 5;
      *(undefined1 *)(puVar1 + 2) = 8;
      memw();
    }
    iVar2 = 0x80 - iVar3;
    if (param_3 != 0) {
      memw();
      (*(code *)&SUB_4008b3d0)((int)puVar1 + iVar3,param_2,param_3);
      iVar2 = iVar2 - param_3;
    }
    FUN_4015a94c(1);
    FUN_4015a8f8(1,puVar1,0x80U - iVar2 & 0xffff,0);
    (*(code *)&SUB_40094d80)(puVar1);
  }
  return;
}

