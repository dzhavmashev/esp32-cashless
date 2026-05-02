// Function : FUN_40173bb0
// Address  : 0x40173bb0
// Size     : 787 bytes


undefined4 FUN_40173bb0(undefined4 *param_1,int *param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined1 auStack_70 [4];
  uint uStack_6c;
  int iStack_60;
  int iStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  int iStack_2c;
  
  if ((param_1 != (undefined4 *)0x0) && (param_1[6] == 0)) {
    (*(code *)&SUB_4008a890)(param_1);
  }
  if (param_2 == (int *)0x3ff96498) {
    param_2 = (int *)param_1[1];
  }
  else if (param_2 == (int *)0x3ff96478) {
    param_2 = (int *)param_1[2];
  }
  else if (param_2 == (int *)0x3ff96458) {
    param_2 = (int *)param_1[3];
  }
  FUN_4018560c(1,&uStack_34);
  if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
    (*(code *)&SUB_40086504)(param_2[0x16]);
  }
  if ((*(ushort *)(param_2 + 3) & 0x108) == 0x108) {
    (*(code *)&SUB_4008a6e8)(param_1,param_2);
  }
  pcVar5 = (code *)param_2[0xb];
  if (pcVar5 == (code *)0x0) {
    uVar3 = 0x1d;
LAB_40173c4a:
    *param_1 = uVar3;
LAB_40173e3c:
    if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
      (*(code *)&SUB_40086534)(param_2[0x16]);
    }
    FUN_4018560c(uStack_34,&uStack_34);
    uVar3 = 0xffffffff;
  }
  else {
    if (param_4 == 1) {
      iVar2 = FUN_40173eec(param_1,param_2);
      if (iVar2 != -1) {
        param_3 = param_3 + iVar2;
        iVar4 = 0;
        goto LAB_40173c5b;
      }
      uVar3 = 0xffffffff;
    }
    else {
      iVar4 = param_4;
      if (param_4 == 2) {
        iVar2 = 0;
        param_4 = 0;
      }
      else {
        if (param_4 != 0) {
          uVar3 = 0x16;
          goto LAB_40173c4a;
        }
        iVar2 = 0;
      }
LAB_40173c5b:
      if (param_2[4] == 0) {
        iStack_2c = param_4;
        (*(code *)&SUB_4008b294)(param_1,param_2);
        param_4 = iStack_2c;
      }
      if ((*(ushort *)(param_2 + 3) & 0x81a) == 0) {
        if ((*(ushort *)(param_2 + 3) & 0x400) == 0) {
          if ((pcVar5 == (code *)0x4008bd5c) && (-1 < *(short *)((int)param_2 + 0xe))) {
            uStack_30 = 0x400;
            iStack_2c = param_4;
            iVar1 = FUN_400fedc8(param_1,(int)*(short *)((int)param_2 + 0xe),auStack_70);
            if ((iVar1 == 0) && ((uStack_6c & 0xf000) == 0x8000)) {
              param_2[0x14] = iStack_44;
              *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | (ushort)uStack_30;
              param_4 = iStack_2c;
              goto LAB_40173cd5;
            }
          }
          *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x800;
        }
        else {
LAB_40173cd5:
          uVar6 = param_3;
          if (iVar4 != 0) {
            iStack_2c = param_4;
            iVar1 = FUN_400fedc8(param_1,(int)*(short *)((int)param_2 + 0xe),auStack_70);
            if (iVar1 != 0) goto LAB_40173e2e;
            uVar6 = param_3 + iStack_60;
            param_4 = iStack_2c;
          }
          if (param_4 == 0) {
            if ((*(ushort *)(param_2 + 3) & 0x1000) == 0) {
              uStack_30 = uVar6;
              iVar2 = (*pcVar5)(param_1,param_2[8],0,1);
              uVar6 = uStack_30;
              if (iVar2 == -1) goto LAB_40173e2e;
            }
            else {
              iVar2 = param_2[0x15];
            }
            iVar2 = iVar2 - param_2[1];
            if (param_2[0xd] != 0) {
              iVar2 = iVar2 - param_2[0x10];
            }
          }
          piVar8 = (int *)param_2[0xd];
          iVar1 = param_2[4];
          if (piVar8 == (int *)0x0) {
            iVar2 = iVar2 - (*param_2 - iVar1);
            iVar7 = param_2[1] + (*param_2 - iVar1);
          }
          else {
            iVar2 = (iVar2 + param_2[1]) - (param_2[0xf] - iVar1);
            iVar7 = (param_2[0xf] - iVar1) + param_2[0x10];
          }
          if ((iVar2 <= (int)uVar6) && (uVar6 < (uint)(iVar2 + iVar7))) {
            *param_2 = iVar1 + (uVar6 - iVar2);
            param_2[1] = iVar7 - (uVar6 - iVar2);
            if (piVar8 != (int *)0x0) {
              if (piVar8 != param_2 + 0x11) {
                (*(code *)&SUB_40094d98)(param_1);
              }
              param_2[0xd] = 0;
            }
            *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xffdf;
            goto LAB_40173dfe;
          }
          iVar1 = param_2[0x14];
          uStack_30 = uVar6;
          iVar2 = (*pcVar5)(param_1,param_2[8],-iVar1 & uVar6,0);
          if (iVar2 != -1) {
            param_2[1] = 0;
            *param_2 = param_2[4];
            if ((int *)param_2[0xd] != (int *)0x0) {
              if ((int *)param_2[0xd] != param_2 + 0x11) {
                (*(code *)&SUB_40094d98)(param_1);
              }
              param_2[0xd] = 0;
            }
            *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xffdf;
            uVar6 = uStack_30 - (-iVar1 & uVar6);
            if (uVar6 == 0) {
LAB_40173dfe:
              (*(code *)&SUB_4008b530)(param_2 + 0x17,0,8);
              if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
                (*(code *)&SUB_40086534)(param_2[0x16]);
              }
              FUN_4018560c(uStack_34,&uStack_34);
              return 0;
            }
            iVar2 = (*(code *)&SUB_4008bb48)(param_1,param_2);
            if ((iVar2 == 0) && (uVar6 <= (uint)param_2[1])) {
              *param_2 = *param_2 + uVar6;
              param_2[1] = param_2[1] - uVar6;
              goto LAB_40173dfe;
            }
          }
        }
      }
LAB_40173e2e:
      iVar2 = (*(code *)&SUB_4008a6e8)(param_1,param_2);
      if ((iVar2 != 0) || (iVar2 = (*pcVar5)(param_1,param_2[8],param_3,iVar4), iVar2 == -1))
      goto LAB_40173e3c;
      if ((int *)param_2[0xd] != (int *)0x0) {
        if ((int *)param_2[0xd] != param_2 + 0x11) {
          (*(code *)&SUB_40094d98)(param_1);
        }
        param_2[0xd] = 0;
      }
      *param_2 = param_2[4];
      param_2[1] = 0;
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xf7df;
      (*(code *)&SUB_4008b530)(param_2 + 0x17,0,8);
      uVar3 = 0;
    }
    if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
      (*(code *)&SUB_40086534)(param_2[0x16]);
    }
    FUN_4018560c(uStack_34,&uStack_34);
  }
  return uVar3;
}

