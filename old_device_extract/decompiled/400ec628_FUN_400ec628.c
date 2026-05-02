// Function : FUN_400ec628
// Address  : 0x400ec628
// Size     : 42 bytes


int FUN_400ec628(undefined4 param_1,undefined1 *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = func_0x4008c024(param_1);
  iVar2 = 0;
  if (uVar1 < 0x10000) {
    *param_2 = (char)(uVar1 >> 8);
    param_2[1] = (char)uVar1;
    func_0x4008b3d8(param_2 + 2,param_1,uVar1);
    iVar2 = uVar1 + 2;
  }
  return iVar2;
}

