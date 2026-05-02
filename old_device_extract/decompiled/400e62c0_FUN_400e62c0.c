// Function : FUN_400e62c0
// Address  : 0x400e62c0
// Size     : 82 bytes


void FUN_400e62c0(undefined4 param_1,undefined4 param_2,short *param_3,int *param_4,
                 undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  short asStack_22 [17];
  
  asStack_22[0] = 0;
  FUN_400f4f6c(param_2,asStack_22);
  if ((int)*param_3 != (int)asStack_22[0]) {
    iVar2 = (int)(short)(asStack_22[0] - *param_3);
    if (iVar2 < 0) {
      iVar2 = (int)asStack_22[0];
    }
    *param_4 = *param_4 + iVar2;
    *param_3 = asStack_22[0];
    uVar1 = FUN_400f1a90();
    *param_5 = uVar1;
    if (19000 < asStack_22[0]) {
      FUN_400f5164(param_2);
      *param_3 = 0;
    }
  }
  return;
}

