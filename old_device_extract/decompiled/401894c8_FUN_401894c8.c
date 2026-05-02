// Function : FUN_401894c8
// Address  : 0x401894c8
// Size     : 98 bytes


void FUN_401894c8(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((((param_1 != 0) && (-1 < (char)*(byte *)(param_1 + 0xb))) &&
      (iVar1 = *(int *)(param_2 + 0x1c), iVar1 == *(int *)(param_1 + 0x60))) &&
     ((*(byte *)(param_1 + 0xb) & 4) == 0)) {
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
    if (*(char *)(param_2 + 0x13) == '\x01') {
      if ((*(uint *)(param_1 + 0x18) & 0x400) == 0) {
        memw();
        FUN_40186cc0(param_1,(int)*(char *)(param_2 + 0xd));
      }
      uVar2 = (uint)*(byte *)(param_2 + 5);
    }
    else {
      if (1 < (byte)(*(char *)(param_2 + 0x13) - 2U)) {
        return;
      }
      uVar2 = (uint)*(byte *)(iVar1 + 8);
      if (DAT_3ffc1a44 != '\0') {
        uVar2 = (uVar2 < 0xb) * uVar2 + (uint)(uVar2 >= 0xb) * 0xb;
      }
    }
    FUN_401645e4(param_1,uVar2);
  }
  return;
}

