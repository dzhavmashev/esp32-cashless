// Function : FUN_40172300
// Address  : 0x40172300
// Size     : 195 bytes


uint FUN_40172300(int *param_1,undefined1 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (((param_2 == (undefined1 *)0x0) || (param_3 == 0)) ||
     ((param_1[2] == param_1[3] && (iVar1 = FUN_40172194(param_1), iVar1 == 0)))) {
    param_3 = -(uint)*(byte *)(param_1 + 5);
  }
  else {
    iVar1 = param_1[3];
    uVar4 = iVar1 - param_1[2];
    if ((uVar4 < param_3) &&
       ((uVar3 = (param_3 - iVar1) + param_1[2], (uint)(*param_1 - iVar1) < uVar3 ||
        (uVar2 = FUN_40172194(param_1), uVar2 < uVar3)))) {
      (*(code *)&SUB_4008b3d0)(param_2,param_1[1] + param_1[2],uVar4);
      param_1[2] = param_1[2] + uVar4;
      for (; param_2 = param_2 + uVar4, uVar3 != 0; uVar3 = uVar3 - uVar4) {
        iVar1 = FUN_40172194(param_1);
        if (iVar1 == 0) {
          return param_3 - uVar3;
        }
        uVar4 = param_1[3] - param_1[2];
        uVar4 = (uVar4 < uVar3) * uVar4 + (uVar4 >= uVar3) * uVar3;
        (*(code *)&SUB_4008b3d0)(param_2,param_1[1] + param_1[2],uVar4);
        param_1[2] = param_1[2] + uVar4;
      }
    }
    else {
      if (param_3 == 1) {
        *param_2 = *(undefined1 *)(param_1[1] + param_1[2]);
      }
      else {
        (*(code *)&SUB_4008b3d0)(param_2,(undefined1 *)(param_1[1] + param_1[2]),param_3);
      }
      param_1[2] = param_1[2] + param_3;
    }
  }
  return param_3;
}

