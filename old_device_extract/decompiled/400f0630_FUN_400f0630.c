// Function : FUN_400f0630
// Address  : 0x400f0630
// Size     : 32 bytes


void FUN_400f0630(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(param_1 + 0x58);
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    FUN_4017435c(param_2,"%02x%02x%02x",uVar1);
    param_2 = param_2 + 2;
  } while (puVar2 != (undefined1 *)(param_1 + 0x68));
  return;
}

