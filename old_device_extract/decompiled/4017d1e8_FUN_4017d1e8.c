// Function : FUN_4017d1e8
// Address  : 0x4017d1e8
// Size     : 262 bytes


undefined4 FUN_4017d1e8(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *local_30;
  undefined4 uStack_2c;
  
  if (param_3[2] != 0) {
    local_30 = (undefined4 *)*param_3;
    uStack_2c = 0;
    uVar4 = 0;
    do {
      if (uVar4 != 0) {
        uVar5 = param_2[2];
        if (uVar4 < uVar5) {
LAB_4017d2b0:
          uVar5 = uVar4;
        }
        else {
          if ((*(ushort *)(param_2 + 3) & 0x480) != 0) {
            iVar2 = *param_2 - param_2[4];
            uVar5 = (param_2[5] * 3) / 2;
            uVar6 = iVar2 + 1 + uVar4;
            iVar3 = (uVar5 < uVar6) * uVar6 + (uVar5 >= uVar6) * uVar5;
            if ((*(ushort *)(param_2 + 3) & 0x400) == 0) {
              iVar1 = (*(code *)&SUB_40094da4)(param_1,param_2[4],iVar3);
              if (iVar1 == 0) {
                (*(code *)&SUB_40094d98)(param_1,param_2[4]);
                goto LAB_4017d294;
              }
            }
            else {
              iVar1 = (*(code *)&SUB_40094d8c)(param_1,iVar3);
              if (iVar1 == 0) {
LAB_4017d294:
                *param_1 = 0xc;
                *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
                param_3[2] = 0;
                param_3[1] = 0;
                return 0xffffffff;
              }
              (*(code *)&SUB_4008b3d0)(iVar1,param_2[4],iVar2);
              *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfb7f | 0x80;
            }
            param_2[4] = iVar1;
            param_2[5] = iVar3;
            *param_2 = iVar1 + iVar2;
            param_2[2] = iVar3 - iVar2;
            uVar5 = uVar4;
          }
          if (uVar4 < uVar5) goto LAB_4017d2b0;
        }
        (*(code *)&SUB_4008b4c8)(*param_2,uStack_2c,uVar5);
        param_2[2] = param_2[2] - uVar5;
        iVar2 = param_3[2];
        *param_2 = *param_2 + uVar5;
        param_3[2] = iVar2 - uVar4;
        if (iVar2 - uVar4 == 0) break;
      }
      uStack_2c = *local_30;
      uVar4 = local_30[1];
      local_30 = local_30 + 2;
    } while( true );
  }
  param_3[1] = 0;
  return 0;
}

