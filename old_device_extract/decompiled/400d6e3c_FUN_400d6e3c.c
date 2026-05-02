// Function : FUN_400d6e3c
// Address  : 0x400d6e3c
// Size     : 22 bytes


bool FUN_400d6e3c(undefined4 param_1,int *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_400f1a9c();
  bVar1 = param_3 <= (uint)(iVar2 - *param_2);
  if (bVar1) {
    *param_2 = iVar2;
  }
  return bVar1;
}

